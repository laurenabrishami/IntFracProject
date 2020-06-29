/******************************************************************************
author: Lauren Abrishami
date: 4/30/20
purpose: There are functions for tokenizing integers and fractions. These functions-
will call another function to return a list (passed to the class constructer) in-
ascending or descending order depending on the string passed to the tokenizing-
function. The list will be ordered using recursive tree traversal, 
with each element being a node on a tree.
                              

*******************************************************************************/

#include "ProcessInput.h"
#include <iostream>

using namespace std;



template <class N> GenericNode<N>::GenericNode(N value) {
    nodeValue = value;
    left = NULL;
    right = NULL;
}

//Adds the root to the tree. An integer or fraction will be added.
template <class N> void GenericNode<N>::InitializeTree(GenericNode<N>* value) {
    root = value;
};

//Adds a node to the tree
template <class N> void GenericNode<N>::InsertIntoTree(GenericNode<N>* NewNode, GenericNode<N>* CurrentNode) {
    if ((NewNode->CompareTo(CurrentNode->GetNodeValue())) < 1) {   //checks if the new node is bigger 
        
        if (CurrentNode->right == NULL) {
            
            CurrentNode->right = NewNode;                                //the new node is placed right of the current
        }
        else {
            
            InsertIntoTree(NewNode, CurrentNode->right);
        }
    }
    else{   
        if(CurrentNode->left == NULL){
            
            CurrentNode->left = NewNode;
        
        }
        else {
            
            InsertIntoTree(NewNode, CurrentNode->left);      //the new node is placed to the right of the-

        }                                                              //current node's right node.

    }
};

//Traverses the tree to sort a list of numbers in ascending order
template <class N> string GenericNode<N>::SortAscending(GenericNode<N>* node, string result) {
    if (node->left != NULL) {
        
        result = SortAscending(node->left, result);  //Tree traversed to leftmost node
    }

    result += node->ToString() + " ";   //Leftmost nodes are placed into the result string.


    if (node->right != NULL) {
        
        result = SortAscending(node->right, result);   //Tree is traversed to the right. Each right node will-
    }                                                  //be placed in result in order.

    return (result);
};

//see above
template <class N> string GenericNode<N>::SortDescending(GenericNode<N>* node, string result) {
    if (node->right != NULL) {
        result = SortDescending(node->right, result);   //Goes to rightmost node.
    }


    result += node->ToString() + " ";    //Right nodes placed in result in descending order


    if (node->left != NULL) {
        result = SortDescending(node->left, result);   //Left traversal. Left nodes placed in descending order.
    }

    return (result);      //Sorted string is returned.
};

template <class N> void GenericNode<N>::SetNodeValue(N value) {

    nodeValue = value;
};
template <class N> GenericNode<N>* GenericNode<N>::GetRoot() {
    return root;
};
template <class N> N GenericNode<N>::GetNodeValue() {
    return nodeValue;
};
template <class N> void GenericNode<N>::SetLeftNode(GenericNode<N>* node) {
    left = node;
};
template <class N> GenericNode<N>* GenericNode<N>::GetLeftNode() {
    return left;
};
template <class N> void GenericNode<N>::SetRightNode(GenericNode<N>* node) {
    right = node;
};
template <class N> GenericNode<N>* GenericNode<N>::GetRightNode() {
    return right;
};
string FractionClass::ToString() {

    return token;
};
void FractionClass::InitializeFraction(string s, double d) {
    token = s;
    fractionValue = d;
};

int FractionClass::CompareTo(double d) {
    if (fractionValue > d) {
        return -1;
    }
    else if (fractionValue < d) {
        return 1;
    }
    else {
        return 0;
    }
};


FractionClass::FractionClass(double value) : GenericNode(value) {
    nodeValue = value;
    left = NULL;
    right = NULL;
}

string IntegerClass::ToString() {

    return token;
};

void IntegerClass::InitializeInt(string s, int d) {
    token = s;
    integerValue = d;
};


int IntegerClass::CompareTo(int value) {
    if (integerValue > value) {
        return -1;
    }
    else if (integerValue < value) {
        return 1;
    }
    else {
        return 0;
    }
};



IntegerClass::IntegerClass(int value) : GenericNode(value) {
    nodeValue = value;
    left = NULL;
    right = NULL;
}

ProcessInput::ProcessInput(string s) {
    InputString = s;
};

const std::string WHITESPACE = " \n\r\t\f\v";

//trims whitespace left of a string
std::string ltrim(const std::string& s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

//trims whitespace right of a string
std::string rtrim(const std::string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

//trims whitespace on both sides
std::string trim(const std::string& s)
{
    return rtrim(ltrim(s));
}

//the parameter will determine if the returned list is in ascending or descending
//order.
string ProcessInput::TokenizeInt(string s) {
    IntegerClass* root = NULL;
    SortType = s;
    int index = 0;
    InputString=trim(InputString);
    
    string temp;
    
    
    for (int i = 0; i < InputString.size(); i++){
            if (InputString.at(i) == '-' && temp.empty()) {
                temp += "-";
            }
            else if (isdigit(InputString.at(i)))
            {

                temp += InputString.at(i);
                if (i == InputString.size() - 1) {


                    TokenArray[index++] = temp;

                }

            }
            //signals start of the next token
            else if (InputString.at(i) == ' ' || InputString.at(i) == ',') {

                
                TokenArray[index++] = temp;
                temp = "";
            }

        }
    
        

    

    for (int i = 0; i < index; i++) {

        
        
        IntegerClass* intNode = new IntegerClass(std::stoi(TokenArray[i]));
        intNode->InitializeInt(TokenArray[i], std::stoi(TokenArray[i]));
        if (i == 0) {
                
                root = intNode;
                intNode->InitializeTree(root);
                SortedString = root->ToString();
        }
        else {
                
                intNode->InsertIntoTree(intNode, root);
                if (i == index - 1) {
                    if (SortType == "ascending") {
                        
                        SortedString = intNode->SortAscending(root, "");
                    }
                    else {
                        
                        SortedString = intNode->SortDescending(root, "");
                        
                    }
                }
        }
    }

    
        return SortedString;
};
    

string ProcessInput::TokenizeFraction(string s) {
   
    
    int index = 0;
    string numer = "";
    string denom = "";
    double fracValue = 0;

    string temp = "";
    FractionClass* root = NULL;
    SortType = s;
    InputString = trim(InputString);
    bool denom_reached = false;
    double double_array[50];
    
    for (int i = 0; i < InputString.size(); i++) {

            if (InputString.at(i) == '-' && numer.empty()) {
                numer += "-";
            }
            if (InputString.at(i) == '-' && denom_reached && denom.empty()) {
                denom += "-";
            }
            else if (isdigit(InputString.at(i)) && denom_reached==false) {
                
                numer += InputString.at(i);
                cout << "numer is now " << numer << endl;
            }
            else if (InputString.at(i) == '/' && !numer.empty()) {
                denom_reached = true;
                printf("denom reached.");
            }
            else if (isdigit(InputString.at(i)) && denom_reached) {
                denom += InputString.at(i);
                cout << "denom is now " << denom << endl;
                if (i == InputString.size() - 1) {

                    printf("reached the end.");
                    double_array[index++] = stod(numer) / stod(denom);


                }
            }
            else if (InputString.at(i) == ' ' || InputString.at(i) == ',') {
                double_array[index++] = stod(numer) / stod(denom);
                numer = "";
                denom = "";
                denom_reached = false;
            }

        }
        for (int i = 0; i < index; i++) {
            FractionClass* fc = new FractionClass(double_array[i]);
            fc->InitializeFraction(to_string(double_array[i]), double_array[i]);
            if (i == 0) {
                root = fc;
                fc->InitializeTree(root);
                SortedString = root->ToString();

            }
            else {
                fc->InsertIntoTree(fc, root);
                if (i == index - 1) {
                    if (SortType == "ascending") {
                        SortedString = fc->SortAscending(root, "");
                    }
                    else {
                        SortedString = fc->SortDescending(root, "");
                    }
                }
            }

        }
    
    

    return SortedString;
};
