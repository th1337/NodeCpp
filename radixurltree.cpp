#include "radixurltree.h"

using namespace std;

RadixUrlTree::RadixUrlTree() {

    root.isleaf = true;
    root.leaf_id = 0;



}


RadixUrlTree::~RadixUrlTree() {

    for(int i=0; i<structure.size(); i++){

        RadixNode* curr = structure[i];

        for(int j=0; j<curr->edges.size(); j++){

            delete curr->edges[i];
        }

        delete curr;

    }



}


pair<string*,int> split_url(string s) {


    std::string delimiter = "/";

    vector<string> tokens;

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


    string* res = new string[tokens.size()];

    for(int i=0; i<tokens.size(); i++){
        res[i] = tokens[i];
    }


    return make_pair(res, tokens.size());

}

struct RadixNode;




string get_param_name(string param) {

    return param.substr(1, param.length()-2);

}


RadixAnalyse* RadixUrlTree::search(string* url, int size, bool grab_arguments) {
    RadixNode * curr = &root;
    int index = 0;
    bool found = true;
    map<string, string> args;

    while(found && index<size){

        found = false;

        for(int i=0; i<curr->edges.size() && !found ; i++){

            RadixEdge* edge = curr->edges[i];



            if(edge->label.compare(url[index])==0){ // we have found where to go !
                found = true;
                curr = edge->target_node;
                index++;

            }else if(grab_arguments && edge->isparam){
                string param_name = get_param_name(edge->label);
                args[param_name] = url[index];

                found = true;
                curr = edge->target_node;
                index++;


            }

        }


    }

    RadixAnalyse* result = new RadixAnalyse;
    result->args = args;
    result->index = index;
    result->node = curr;

    return result;


}


void RadixUrlTree::insert(string URL, int code) {

    pair<string*, int> split = split_url(URL);

    string* url = split.first;
    int size = split.second;

    RadixAnalyse* res = search(url, size, false);


    RadixNode* curr = res->node;



    for(int i=res->index; i<size; i++) { //we insert our word

        RadixNode* node = new RadixNode;
        node->isleaf = false;

        RadixEdge* edge = new RadixEdge;
        edge->label = url[i];
        if(url[i].at(0)=='{' && url[i].at(url[i].length()-1)=='}'){//we have a parameter

            edge->isparam=true;
        }else{
            edge->isparam = false;
        }
        edge->target_node = node;


        curr->edges.push_back(edge);

        structure.push_back(node);

        curr = node;

    }
    curr->isleaf = true;
    curr->leaf_id = code;

    delete res; // we free the memory allocated for the analyse




}

RadixAnalyse* RadixUrlTree::find_url(string url) {


    pair<string*, int> split = split_url(url);

    RadixAnalyse* res = search(split.first, split.second, true);

    delete [] split.first;
    if(res->index ==  split.second && res->node->isleaf){
        res->code = res->node->leaf_id;
        res->found = true;
        return res;
    }

    res->found=false;
    return res;

}


