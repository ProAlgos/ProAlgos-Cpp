#pragma once
#include <vector>
#include <memory>

//Vector 2 class to determine points

struct Vector2 
{
	float x;
	float y;
	Vector2(float _x = 0.f, float _y = 0.f) : x(_x) , y(_y) {}
};

//Rectangular class to determine squares.
struct Rect_AABB {
	Vector2 centerPoint;
	Vector2 halfDimension;

	Rect_AABB() {
		centerPoint = Vector2(0,0);
		halfDimension = Vector2(50, 50);
	}

	Rect_AABB(const Vector2& _center, const Vector2& _halfDimension) {
		centerPoint = _center;
		halfDimension = _halfDimension;
	}

	bool ContainsPoint(const Vector2& point) const {
		if (point.x < centerPoint.x + halfDimension.x && point.x > centerPoint.x - halfDimension.x) {
			if (point.y < centerPoint.y + halfDimension.y && point.y > centerPoint.y - halfDimension.y) {
				return true;
			}
		}
		return false;
	}

	bool Intersects_AABB (const Rect_AABB& other) const {
		//if this right is greater then that left or if this left is greater then that right
		if (centerPoint.x + halfDimension.x > other.centerPoint.x - halfDimension.x || 
			centerPoint.x - halfDimension.x < other.centerPoint.x + halfDimension.x) {
			//This bottom > that top
			if (centerPoint.y + halfDimension.y > other.centerPoint.y - halfDimension.y ||
				centerPoint.y - halfDimension.y < other.centerPoint.y + halfDimension.y)
				return true;
		}
		return false;
	}
};

template <typename T>

//Struct used to hold data. Using raw pointers here, but can
//easily be changed to std smart pointers.
struct Data_Node
{
	Vector2 point;
	T * data;
	Data_Node(Vector2 _point, T * _data) : point(_point), data(_data) {}

	~Data_Node() {}
};

template <typename T>
class PointQuadTree
{
private:
	const int QT_NODE_MAX_CAPACITY = 1;
	Rect_AABB boundaries;
	std::vector<Data_Node<T>> points;

	//children
	PointQuadTree * northWest = nullptr;
	PointQuadTree * northEast = nullptr;
	PointQuadTree * southWest = nullptr;
	PointQuadTree * southEast = nullptr;

public:
	PointQuadTree(Rect_AABB _boundaries);
	~PointQuadTree();

	bool Insert(Data_Node<T> data);
	// create four children that fully divide this quad into four quads of equal area
	void Subdivide();

	//returns a vector containing all the points inside range.
	std::vector<Data_Node<T>> QueryRange(Rect_AABB& range);

	//preferred method of query. Does the same thing except it does not return a copy of the vector and requires the user to put one in
	void QueryRange_private_recursive(Rect_AABB& range, std::vector<Data_Node<T>>& result);
};

/*

Point QuadTree
-------------------
Data structure adapted from binary trees used to represent 2D information. Quadtrees have the following feature

1. They decompose space into adaptable cells
2. Each cell (or bucket) has a maximum capacity. When maximum capacity is reached, the bucket splits
3. The tree directory follows the spatial decomposition of the quadtree.

New points are added such that the cell that contains it is divided into quadrants by the vertical and horizontal lines that run through the point.
Consequently, cells are rectangular but not necessarily square.

Since the division of the plane is decided by the order of point-insertion,
the tree's height is sensitive to and dependent on insertion order.
Inserting in a "bad" order can lead to a tree of height linear in the number of input points (at which point it becomes a linked-list).
If the point-set is static, pre-processing can be done to create a tree of balanced height.
*/

/*
Contructor
*/
template <typename T>
PointQuadTree<T>::PointQuadTree(Rect_AABB _boundaries) : northWest(nullptr), northEast(nullptr), southEast(nullptr), southWest(nullptr)
{
	boundaries = _boundaries;
	points = {};
}

/*
Destructor
*/
template <typename T>
PointQuadTree<T>::~PointQuadTree()
{
	delete northWest;
	delete northEast;
	delete southEast;
	delete southWest;

}

/*
Insert
----
Returns true or false depending on whether successful insertion, subdividing each node when necessary.

Time complexity
---------------
O(log n)
Space complexity
---------------
O(log n)
*/
template <typename T>
bool PointQuadTree<T>::Insert(Data_Node<T> data) {
	//If data does not belong in our point
	if (!boundaries.ContainsPoint(data.point)) {
		return false;
	}

	//If data belongs here and we are not full
	if (points.size() < QT_NODE_MAX_CAPACITY) {
		points.push_back(data);
		return true;
	}

	//We have too much data and should split it into Quads
	//If any of the quadrants are created, none of them are null so
	//one check is enough
	if (northWest == nullptr)
		Subdivide();

	if (northWest->Insert(data)) return true;
	if (northEast->Insert(data)) return true;
	if (southEast->Insert(data)) return true;
	if (southWest->Insert(data)) return true;

	//otherwise node cannot be inserted. This should never happen
	return false;
}

/*
Subdivide
----
Creates four equally spaced rectangle nodes as children.

Time complexity
---------------
O(1)
Space complexity
---------------
O(1)
*/
template <typename T>
void PointQuadTree<T>::Subdivide() {
	Vector2 children_size = { boundaries.halfDimension.x, boundaries.halfDimension.y };

	Vector2 child_center = { boundaries.centerPoint.x - children_size.x, boundaries.centerPoint.y - children_size.y };
	southWest = new PointQuadTree(Rect_AABB(child_center, children_size));

	child_center = { boundaries.centerPoint.x + children_size.x, boundaries.centerPoint.y - children_size.y };
	southEast = new PointQuadTree(Rect_AABB(child_center, children_size));

	child_center = { boundaries.centerPoint.x - children_size.x, boundaries.centerPoint.y + children_size.y };
	northWest = new PointQuadTree(Rect_AABB(child_center, children_size));

	child_center = { boundaries.centerPoint.x + children_size.x, boundaries.centerPoint.y + children_size.y };
	northEast = new PointQuadTree(Rect_AABB(child_center, children_size));
}

/*
QueryRange
----
Public function that hide the recursive function QueryRange_private_recursive.

Time complexity
---------------
Usually O(log n). Worse case O(n), where n is the amount of objects, and in worse case should be height of tree.
Space complexity
---------------

Space Complexity
----------------
O(1)
*/
template <typename T>
std::vector<Data_Node<T>> PointQuadTree<T>::QueryRange(Rect_AABB& range) {
	std::vector<Data_Node<T>> results = {};
	QueryRange_private_recursive(range, results);

	return results;
}

/*
QueryRange_private_recursive
----
Public function that hide the recursive function QueryRange_private_recursive.

Time complexity
---------------
Usually O(log n). Worse case O(n), where n is the amount of objects, and in worse case should be height of tree.

Space complexity
---------------
O(1)
*/
template <typename T>
void PointQuadTree<T>::QueryRange_private_recursive(Rect_AABB& range, std::vector<Data_Node<T>>& result) {
	//abort if not within boundary
	if (!boundaries.Intersects_AABB(range)) {
		return;	//empty
	}

	//check objects at this level
	for each (auto point in points) {
		if (range.ContainsPoint(point)) {
			results.push_back(point);
		}
	}

	//terminite if no children
	if (northEast == nullpr)
		return results;

	//otherwise query all children for results
	northEast->QueryRange_private_recursive(range, result);
	northWest->QueryRange_private_recursive(range, result);
	southEast->QueryRange_private_recursive(range, result);
	southWest->QueryRange_private_recursive(range, result);
}
