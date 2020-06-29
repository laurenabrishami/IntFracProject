#pragma once
#include <string>
using namespace std;

template <class N> class GenericNode {
protected:
    GenericNode<N>* right = NULL;
    GenericNode<N>* left = NULL;
    N nodeValue;
    GenericNode<N>* root = NULL;
public:
    GenericNode(N value);
    virtual string ToString() = 0;
    virtual int CompareTo(N value) = 0;
    void InitializeTree(GenericNode<N>* value);
    
    void InsertIntoTree(GenericNode<N>* NewNode, GenericNode<N>* CurrentNode);
    
    string SortAscending(GenericNode<N>* node, string result);
    string SortDescending(GenericNode<N>* node, string result);
    void SetNodeValue(N value);
    GenericNode<N>* GetRoot();
    N GetNodeValue();
    void SetLeftNode(GenericNode<N>* node);
    GenericNode<N>* GetLeftNode();
    void SetRightNode(GenericNode<N>* node);
    GenericNode<N>* GetRightNode();

};

class IntegerClass : public GenericNode<int> {
private:
    string token;
    int integerValue = 0;

public:
    IntegerClass(int value);
    void InitializeInt(string s, int d);
    string ToString();
    int CompareTo(int value);


};

class FractionClass : public GenericNode<double> {
private:
    string token;
    double fractionValue = 0;
    string fractionParts[2];

public:
    FractionClass(double value);
    void InitializeFraction(string s, double d);
    string ToString();
    int CompareTo(double d);


};

class ProcessInput {
private:

    string InputString;
    string TokenArray[50];
    string SortType;
    string SortedString;

public:
    ProcessInput(string s);
    string TokenizeInt(string s);
    string TokenizeFraction(string s);
};

