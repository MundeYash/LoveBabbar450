
/*

Huffman Coding : given the charater with their frequency convert character with their huffman code

*/

#include <bits/stdc++.h>
using namespace std;

// creation of node for tree
class node
{
public:
    int data;
    node *left;
    node *right;

    // default constructor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
class comparator
{
public:
    // operator overloading
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

// creating traverse function for storing the answer of corresponding huffman code
void traverse(node *root, vector<string> &ans, string output)
{
    // base case
    if (root->left == NULL and root->right == NULL)
    {
        ans.push_back(output);
        return;
    }

    // recursive case
    traverse(root->left, ans, output + '0');
    traverse(root->right, ans, output + '1');
}

// function for the huffman code
vector<string> huffmanCode(string S, vector<int> freq, int n)
{

    // creation min heap on the basis of custom comparator

    priority_queue<node *, vector<node *>, comparator> pq;

    for (int i = 0; i < n; i++)
    {
        node *newNode = new node(freq[i]);

        // pusing the nodes into the priority queue
        pq.push(newNode);
    }

    // work for finding the minimum two nodes and merging them to form tree
    while (pq.size() > 1)
    {
        node *first = pq.top();
        pq.pop();
        node *second = pq.top();
        pq.pop();

        node *newNode = new node(first->data + second->data);

        newNode->left = first;
        newNode->right = second;
        pq.push(newNode);
    }

    // remaining node in the priority queue will be the root node of the tree
    node *root = pq.top();
    pq.pop();
    vector<string> ans;
    string output;
    traverse(root, ans, output);

    return ans;
}

// function for printing the string ;
void print(vector<string> ans, int n, string  s )
{
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << "->" << ans[i] << endl;
    }
}
int main()
{
    string s = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    int n = freq.size();
    vector<string> ans = huffmanCode(s, freq, n);
    print(ans, n, s);
    cout << "huffman coding : " << endl;
    return 0;
}

/*
gfg : https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1 (rem)
*/