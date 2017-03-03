/*
    Knuth-Morris-Pratt's Algorithm:
    A String Search Algorithm, that searches for a given "word" (string) in a "text" (another string).
    It uses the fact that when a mismatch occurs, one can jump further in the text than a naive algorithm
    would (i.e., only +1). With KMP the algorithm can jump up to all the length of the searched word.
    
    Time complexity is O(n + m), where n is the length of the word, and m is the length of the text.    
*/

#include <cstdio>
#include <vector>
#include <string>

using namespace std;


//Create the table of partial matches
vector<int> kmpPreprocess(string word){
	//table of partial matches so that the algorithm knows where to jump to
	vector<int> table = vector<int>(word.size());
	//default initialization
	table[0] = -1; 
	int i=0,j=-1;
		
	//Loop through the entire word looking for matches and mismatches
	while(i < word.size()){
		while(j >= 0 && word[i] != word[j]) //in cases where there is a mismatch, reset j with the table
			j = table[j];
		//when there is a match, advance both counters, i and j
		i++;
		j++;
		//set the ith element in table with the counter in j, meaning how much it should disconsider when jumping further in text
		table[i] = j;
	}
	
	return table;
}


//Searches for occurrences of the word in the text.
//Return: a vector containing the first index of each occurrence of word.
vector<int> kmpSearch(string word, string text){
	//obtain the table of partial matches
	vector<int> table = kmpPreprocess(word);
	//vector with the indexes of occurences of the word
	vector<int> indexes;
	int i=0,j=0;
	
	//Loop through the entire text, just like in the preprocessing
	while(i < text.size()){
		while(j >= 0 && text[i] != word[j]) //in cases where there is a mismatch, reset j with the table
			j = table[j];
		//update counters
		i++;
		j++;
		
		//save the index of the word occurrence
		if(j == word.size()){
			indexes.push_back(i-j);
			//update j for further matches
			j = table[j];
		}
		
	}
	
	return indexes;
}


//For testing purposes
int main(){

	//This test should print: 
	//282 : est
	//675 : est
	string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam blandit, magna posuere ultricies dapibus, nulla diam ullamcorper lorem, vel consequat lorem mi et mauris. Integer tempus luctus dignissim. Etiam pretium nisl sed aliquam rhoncus. Duis sodales sapien eu nibh dignissim egestas. Fusce non quam nec leo interdum interdum. Fusce cursus, sem quis congue tincidunt, mi velit tempus ante, non imperdiet nunc leo vitae nulla. Suspendisse at facilisis tortor. Morbi sapien purus, eleifend id volutpat vitae, tempus non arcu. Suspendisse vitae sollicitudin ex. Nunc rhoncus consectetur rhoncus. Proin tristique nunc in nibh pellentesque, ut aliquam nisl dictum. Ut rhoncus est non velit ullamcorper semper. Donec in fermentum felis. Mauris sollicitudin quis tortor pharetra fringilla. Morbi quis nunc sed enim auctor viverra mollis at enim."; 
	string word = "est";

	vector<int> indexes = kmpSearch(word, text);
		
	for(int i=0;i<indexes.size();i++){
		printf("%i : %s\n", indexes[i], text.substr(indexes[i], word.size()).c_str());
	}
	
	return 0;
}
