#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <ctime>
#include <string>


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


    void selectNodeFromCluster(){
        count = 0;
                int clusterno;
                int selectednode;
                cout<<"Enter the cluster number from 0 to 9: ";
                cin>>clusterno;
                Node nodelist[10];
                for(int i=0;i<65;i++){
                  if(Stakernodes[i].clustergrpno==clusterno){
                    nodelist[count] = Stakernodes[i];
                    count++;
                  }
                }
                   cout<< "\n Staker Nodes present in this cluster are: \n";
                for(int i=0;i<count;i++){
                  cout<< "\nStakerNode "<<i<<" :";
                  cout<< nodelist[i].nodeid<<"--";
                  cout<< nodelist[i].value<<"--";
                  cout<< nodelist[i].clustergrpno<<"-:) \n";
                }

                srand((int)time(0));
                int randno = rand() % clusters[clusterno][1] +1;
               cout<<"\n Cluster Total: "<<clusters[clusterno][1]<<"\n";
              for(int i=0; i<10;i++){
                    randno -= nodelist[i].value;
                      if(randno<=0){
                          selectednode = i;
                          break;
                          }
                      else{
                          continue;
                          }
                }

                cout<<"\n Selected node is as follows: \n"<<"NodeID: "<<nodelist[selectednode].nodeid<<"\nValue: "<<nodelist[selectednode].value;
    }
};

int main(){
     DPOS dpos;  
   
    dpos.firstArrayCreation();
    dpos.clusterCreation();
     cout<<" \n";
     dpos.nodeCreationAndClassification();
     dpos.selectNodeFromCluster();
      cout<<"\n";
  
  
 }
