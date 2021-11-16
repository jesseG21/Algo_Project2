#ifndef _ALIGNMENT_H
#define _ALIGNMENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue> 
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std; 




typedef struct align{
    int score; 
    vector<int> sequence; 
}align_t; 


/*
Class to work with different alignment functions. Store information into a data
struct that contains alignment and then use score as a key in map to retrieve score and sequence
Alignment will start with two sequences retrieved from the file -> seq1 and seq2
seq#_l -> stores the length of the two sequences from the input file
soln will be retrieved by accessing solution struct
*/



class Alignment
{
private:
    
    queue<int> seq1; 
    int seq1_l; 
    
    queue<int> seq2;
    int seq2_l; 

    stack<int> same_num; 
    align_t target; 
    align_t soln; 
public:
    Alignment(){}
    

    void addSequenceLength(int,int); 
    void addSequence_1(float);
    void addSequence_2(float); 
    void addTarget(float); 
    int CalculateScore(align_t, align_t);
    void combineSequence(align_t); 
    void MaxAlignment(int index); 
    void printAll();
    void printMax(); 
};










#endif