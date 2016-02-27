#include "radixurltree.h"
#include <iostream>
using namespace std;
const int RESERVE_URL = 1000;

RadixUrlTree::RadixUrlTree() {

    RadixNode root;
    root.is_leaf_ = false;
    structure_.reserve(RESERVE_URL);
    structure_.push_back(root);
    this->root_ = & (structure_[0]);

}


RadixUrlTree::~RadixUrlTree() {

}




void SplitUrl(string& s, vector<string>& tokens) {


    std::string delimiter = "/";

    //vector<string> tokens;

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        if(token.length()>0){
            tokens.push_back(token);
        }
        s.erase(0, pos + delimiter.length());
    }

    if(s.size()>0){
        tokens.push_back(s);
    }


}

struct RadixNode;




string get_param_name(string param) {

    return param.substr(1, param.length()-2);

}


RadixUrlTree::RadixAnalyse RadixUrlTree::Search(vector<string>& url, bool grab_arguments) {
    RadixNode * curr = root_;
    int index = 0;
    bool found = true;
    int size = url.size();
    map<string, string> args;

    while(found && index<size){

        found = false;

        for(unsigned int i=0; i<curr->edges_.size() && !found ; i++){

            RadixEdge edge = curr->edges_[i];



            if(edge.label_.compare(url[index])==0){ // we have found where to go !
                found = true;
                curr = edge.target_node_;
                index++;

            }else if(grab_arguments && edge.is_param_){
                string param_name = get_param_name(edge.label_);
                args[param_name] = url[index];

                found = true;
                curr = edge.target_node_;
                index++;


            }

        }


    }

    RadixAnalyse result;
    result.args_ = args;
    result.index_ = index;
    result.node_ = curr;

    return result;


}


void RadixUrlTree::Insert(string url, int code) {

    vector<string> split;

    SplitUrl(url, split);


    RadixAnalyse res = Search(split, false);


    RadixNode* curr = res.node_;



    for(unsigned int i=res.index_; i<split.size(); i++) { //we insert our word

        RadixNode node;
        node.is_leaf_ = false;
        structure_.push_back(node);
        RadixNode* node_pointer = &(structure_[structure_.size()-1]);


        RadixEdge edge;
        curr->edges_.push_back(edge);

        RadixEdge* edge_pointer = &(curr->edges_[curr->edges_.size()-1]);

        edge_pointer->label_ = split[i];

        if(split[i].at(0)=='{' && split[i].at(split[i].length()-1)=='}'){//we have a parameter


            edge_pointer->is_param_ = true;
        }else{
            edge_pointer->is_param_ = false;
        }
        edge_pointer->target_node_ = node_pointer;

        curr = node_pointer;


    }
    curr->is_leaf_ = true;
    curr->leaf_id_ = code;



}

RadixUrlTree::RadixAnalyse RadixUrlTree::FindUrl(string url) {

    vector<string> split;

    SplitUrl(url, split);

    RadixAnalyse res = Search(split, true);

    if((unsigned int)res.index_ ==  split.size() && res.node_->is_leaf_){
        res.code_ = res.node_->leaf_id_;
        res.found_ = true;
        return res;
    }

    res.found_ = false;
    res.code_ = -1;
    return res;

}


