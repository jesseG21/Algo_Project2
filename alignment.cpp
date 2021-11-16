#include "alignment.h"

//Global Map of solutions
unordered_map<int,align_t> seq_soln; 
int max_score = 0; 
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

//calculates score for sequence and stores value as key for map
int Alignment::CalculateScore(align_t target,align_t sequence){

    int score = 0;
    int dot = 0;

    for(int i = 0; i < sequence.sequence.size(); i++){

        dot = sequence.sequence[i] * target.sequence[i];
        score = dot + score;
    }
    //sequence.score = score;

    return score; 
}

void Alignment::MaxAlignment(int index){
    //check to see if sequences arent empty
    int score =0;
    //cout << "Here";
    if(!seq1.empty() && !seq2.empty()){
        /*check to see if we can find a match pop doubles onto a new stack
          if we find a match we push to soln sequence and add to map
        */
        if(seq1.front() == target.sequence.at(index) ){
            soln.sequence.push_back(seq1.front()); 
            score = CalculateScore(target, soln);
            if(score > max_score){
                max_score = score; 
            }
            seq_soln.emplace(score,soln); 
            seq1.pop(); 
            MaxAlignment(index+1); 
        }
        else if(seq2.front() == target.sequence.at(index) ){
            soln.sequence.push_back(seq2.front());
            score = CalculateScore(target,soln); 
            if(score > max_score){
                max_score = score; 
            }
            seq_soln.emplace(score,soln); 
            seq2.pop();
            MaxAlignment(index+1); 
        }

        

    }
    //if were done print the max score
    else{
         
        printMax(); 
    }
}

void Alignment::printMax(){
    soln = seq_soln.at(max_score); 
    
    cout << "Score:" << max_score << endl; 
    cout << "Target:"; 
    for(int i=0; i<soln.sequence.size();i++){
        cout << soln.sequence.at(i) << ' '; 
    }
}

/*void Alignment :: combineSequence(align_t target){

    for(int i = 0; i <target.sequence.size();i++){
    vector<int> diff1;
    vector<int> diff2;
    diff1.push_back(abs(seq1.front() - target.sequence[i]));
    diff2.push_back(abs(seq2.front() - target.sequence[i]));

    if(diff1[i] < diff2[i]){
        soln.sequence.push_back(seq1.front());
        seq1.pop();
    }
    else if(diff2[i] < diff1[i]){

        soln.sequence.push_back(seq2.front());
        seq2.pop();
    }
    else if(diff1[i] == diff2[i]){)

*/