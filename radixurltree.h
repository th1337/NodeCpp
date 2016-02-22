#ifndef RADIXURLTREE_H
#define RADIXURLTREE_H

#include <vector>
#include <string.h>
#include <map>

struct RadixNode;


struct RadixEdge{

    std::string label;
    bool isparam;

    RadixNode* target_node;

};


struct RadixNode{

    bool isleaf;
    int leaf_id;

    bool is_leaf(){

        return isleaf;
    }

    std::vector<RadixEdge*> edges;

};



struct RadixAnalyse{

    RadixNode* node;
    int index;
    bool found;
    int code;
    std::map<std::string, std::string> args;

};





class RadixUrlTree {

public:
    void insert(std::string URL, int code);
    RadixAnalyse* find_url(std::string url);


    RadixUrlTree();
    ~RadixUrlTree();



private:
    RadixAnalyse* search(std::string* url, int size, bool grab_arguments);


    RadixNode root;
    std::vector<RadixNode*> structure;



};

#endif // RADIXURLTREE_H
