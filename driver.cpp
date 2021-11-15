#include "alignment.h"


/*
Read the data from input file and calculate the alignment score
*/
//Global Map of solutions
unordered_map<int,align_t> seq_soln; 
int main(){
    ifstream in; 
    Alignment align; 
    
    string l1, l2, data;  
    
    
    in.open("sample-input.txt"); 

    //Retrieve all data
    if(!in.is_open()){
        cout << "Failed to open file\n";
    }
    else{
        cout << "Success\n";
        /*
            line 1: n = length of seq1 and m = length seq2
            line 2: n ->real numbers for seq1
            line 3: m ->real numbers for seq2
            line 4: n + m ->real numbers for target
        */
        in >> l1 >> l2; 
        //cout << l1 << ' ' << l2 << endl;
        align.addSequenceLength(stoi(l1), stoi(l2)); 
        
        /*Extract the data
          I figured that by converting the decimal numbers to whole numbers they would be easier to work with
          we can convert back to floating point later but results should be the same
        */ 
        for(int i=0; i<stoi(l1);i++){
            in >> data; 
            //cout << (stof(data) * 100) << ' '; 
            align.addSequence_1(stof(data)*100);

        }
        puts(""); 
        for(int i=0; i<stoi(l2);i++){
            in >> data; 
            //cout << (stof(data)*100) << ' '; 
            align.addSequence_2(stof(data)*100); 
        }
        puts("");
        for(int i=0; i<(stoi(l1)+stoi(l2));i++){
            in >> data;
            //cout << (stof(data)*100) << ' '; 
            align.addTarget(stof(data)*100); 
        }
    }
    
    align.printAll(); 
    
    in.close(); 
    return 0; 
}