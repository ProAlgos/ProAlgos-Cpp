#pragma once
#include <vector>

struct Vector2 
{
	float x;
	float y;
	Vector2(float _x = 0.f, float _y = 0.f): x(_x) , y(_y) {}
};

struct Rect_AABB {
	Vector2 centerPoint;
	Vector2 halfDimension;

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
struct Data_Node
{
	Vector2 point;
	T * data;

	Data_Node(Vector2 _point, T * _data) {
		point = _point;
		data = _data;
	}

	~Data_Node() {
		delete data;
		data = nullptr;
	}
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
	void QueryRange_private_recursive(Rect_AABB& range, std::vector<Data_Node<T>>& result);

public:
	PointQuadTree(Rect_AABB _boundaries);
	~PointQuadTree();

	bool Insert(Data_Node data);
	void Subdivide();	// create four children that fully divide this quad into four quads of equal area
	std::vector<Data_Node<T>> QueryRange(Rect_AABB& range);
};

