#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

class DPOS{

   public:
   int N[100];
   int totalsum;
   int clusters[10][2];
   int id;
   
   struct Node {
         int nodeid;
         int value;
         int clustergrpno;
         double clusterprob;
         double totalprob;
         bool staker;
   };
 
   Node Stakernodes[80], Validatornodes[40];
   
   void firstArrayCreation(){
      totalsum=0;
       for (int i = 0; i < 100; i++) {
    int temp = rand() % 5;
    N[i] = temp % 3;
    totalsum += N[i];
      }  
     }

   void displayArray(){
      firstArrayCreation();
      cout<< "\n Total sum : "<<totalsum<<"\n";
       // for (int i = 0; i < 100; i++) {
       //     cout<< N[i]<<"\n";
       // }
     }
  
   void clusterCreation(){
      int m = 0;
       for (int i = 0; i < 10; i++) {
            clusters[i][0] = i;
            int sum = 0;
             for (int j=0; j < 10; j++) {
                  sum += N[m];
                  m++;
             }
            clusters[i][1] = sum;
       }
    
     }
    
   void displayClusters(){
         clusterCreation();
         // for (int i = 0; i < 10; i++) {
         //    cout<<"\n Cluster "<<i<<" :: ";   
         //    for (int j = 1; j < 2; j=j+2) {
         //      cout<<clusters[i][j]<<"\t";
         //       }
         // }
      
     }

    int s;
    int v;
    int clusterno;
    int count;
     void nodeCreationAndClassification(){
      id=1001; s=0; v=0; clusterno=0; count=0;
       for(int i=0; i<100; i++){
            if(N[i]==0){
                Validatornodes[v].nodeid = id;
                Validatornodes[v].value = N[i];
                Validatornodes[v].clustergrpno = clusterno;
                Validatornodes[v].clusterprob =0;
                Validatornodes[v].totalprob = 0;
                Validatornodes[v].staker = false;
                v++;                     
            }
            else{
                Stakernodes[s].nodeid = id;
                Stakernodes[s].value = N[i];
                Stakernodes[s].clustergrpno = clusterno;
                Stakernodes[s].clusterprob = N[i]*0.1/clusters[clusterno][1];
                Stakernodes[s].totalprob = N[i]*0.1/totalsum;
                Stakernodes[s].staker = true;  
                s++;  
            }
            count++;
            if(count>9){ count=0; clusterno++;}
            id++;
       }
     }
  inline const char * const BoolToString(bool b)
{
  return b ? "true" : "false";
}   

   void displayStakerNodes(){
          for(int i=0; i<65; i++){

              cout<< "StakerNode "<<i<<" :";
              cout<< Stakernodes[i].nodeid<<"--";
              cout<< Stakernodes[i].value<<"--";
              cout<< Stakernodes[i].clustergrpno<<"--";
              cout<< Stakernodes[i].clusterprob<<"--";
              cout<< Stakernodes[i].totalprob<<"-:)";
              //cout<< BoolToString(Stakernodes[i].staker);
              
      }
   }

   void displayValidatorNodes(){
    
      for(int i=0; i<35; i++){
              cout<< "Validatornode "<<i<<" :";
              cout<< Validatornodes[i].nodeid<<"--";
              //cout<< Validatornodes[i].value<<"--";
              cout<< Validatornodes[i].clustergrpno<<"-:)";
              //cout<< Validatornodes[i].clusterprob<<"--";
              //cout<< Validatornodes[i].totalprob<<"-:)";
              //cout<< BoolToString(Validatornodes[i].staker);
             
      }
   }

    void selectNodeFromCluster(){
                int clusterno;
                cout<<"Select the cluster:"
                cin>>clusterno;
                
    }
};

int main(){
     DPOS dpos;  
   
    dpos.displayArray();
    dpos.displayClusters();
     cout<<" \n";
     dpos.nodeCreationAndClassification();
     dpos.displayValidatorNodes();
     dpos.displayStakerNodes();
 
      cout<<"\n";
   
   

 }
