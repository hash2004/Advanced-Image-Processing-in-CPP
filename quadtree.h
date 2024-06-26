#pragma once
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class qt_node {
public:
    bool flag;
    int pixel_value;
    int* p;
    qt_node()
    {
        flag = false;
    }
   

    //prows/pcols are constant in every node
    int prows;
    int pcols;



    //what parts of the image this node represents
    int r_min;
    int r_max;
    int c_min;
    int c_max;

    //pixel value deviation in the node
    int deviation;

    qt_node* NW;
    qt_node* NE;
    qt_node* SE;
    qt_node* SW;


};

struct qt {
    qt_node* quadNode = new qt_node;
    qt();
};
//creates a qt_node
qt_node* init_node();

//adds pixel values, r_min/max, c_min/max
void add_values(qt_node* q, int* p, int num_rows, int num_cols);


//splits a qt_node into 4 smaller nodes with corresponding pixel values
void split_qt_node(qt_node* q);


//calculates the deviation within the pixels of the node
int get_node_deviation(qt_node* q);

//calculates the average pixel value in the assigned range.
float get_avg_pxvalue(qt_node* q);

//gets the variance in the range of q
float get_pixel_variance(qt_node* q);

//builds the quad-tree based on the specified maximum pixel value variance
//splits starting node and successive nodes into child nodes
void build_tree(qt_node* start, int max_var);

//Unpacks the tree data into an array
//Not used in this implementation
void unpack_tree(qt_node* start, int* unpacked, int total_rows, int total_cols);

//Unpacks the tree data into an OpenCV Matrix structure

//counts leaf nodes of an already built tree
//can be a proxy for the number of pixel representations
int count_tree_nodes(qt_node* start);

//Counts the number of pixels used
//Just for checking, should be equal to the image's rows * cols
int check_num_pixels(qt_node* start);