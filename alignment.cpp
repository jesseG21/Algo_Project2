#include "alignment.h"


//Keep track of the length of the sequences in case we need them later
void Alignment::addSequenceLength(int seq1, int seq2){
    seq1_l = seq1; 
    seq2_l = seq2; 
}

//push elemets into our queues
void Alignment::addSequence_1(float data){
    seq1.push(data);
}
void Alignment::addSequence_2(float data){
    seq2.push(data); 
}

void Alignment::addTarget(float data){
    target.score = 0; 
    target.sequence.push_back(data); 
}

/*Calling this function prints all stored data but at the cost of pop everything off 
  the queues
*/
void Alignment::printAll(){
    cout << "Stack 1:"; 
    while(!seq1.empty()){
        cout << seq1.front() << ' ';
        seq1.pop(); 
    }
    puts("");
    cout << "-------------------------------" << endl; 
    
    cout << "Stack 2:"; 
    while(!seq2.empty()){
        cout << seq2.front() << ' ';
        seq2.pop(); 
    }
    puts("");
    cout << "-------------------------------" << endl; 
    cout << "Target score:" << target.score << endl; 
    cout << "Target:";
    for(int i=0; i< (seq1_l+seq2_l); i++){
        cout << target.sequence.at(i) << ' ';
    }
}