#ifndef RADIXURLTREE_H
#define RADIXURLTREE_H

#include <vector>
#include <string.h>
#include <map>

using namespace std;


class RadixUrlTree {

public:

    class RadixAnalyse;

    void Insert(string URL, int code);
    RadixAnalyse FindUrl(string url);


    RadixUrlTree();
    ~RadixUrlTree();




private:
    RadixAnalyse Search(string* url, int size, bool grab_arguments);

    class RadixNode;
    class RadixEdge;

    RadixNode* root_;
    vector<RadixNode> structure_;



};

class RadixUrlTree::RadixEdge{
public:
    string label_;
    bool is_param_;

    RadixUrlTree::RadixNode* target_node_;

};


class RadixUrlTree::RadixNode{
public:
    bool is_leaf_;
    int leaf_id_;

    bool is_leaf(){

        return is_leaf_;
    }

    vector<RadixUrlTree::RadixEdge> edges_;

};



class RadixUrlTree::RadixAnalyse{
public:
    RadixUrlTree::RadixNode* node_;
    int index_;
    bool found_;
    int code_;
    map<std::string, string> args_;

};


#endif // RADIXURLTREE_H
