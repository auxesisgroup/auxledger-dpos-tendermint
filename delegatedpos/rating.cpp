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
         float rating;
         bool availability;
         bool staker;
   };
 
   Node Stakernodes[80], Validatornodes[40];
   
    inline const char * const BoolToString(bool b)
    {
      return b ? "Available" : "NotAvailable";
    }

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
    int vcount;
     void nodeCreationAndClassification(){
      id=1001; s=0; v=0; clusterno=0; count=0;
       for(int i=0; i<100; i++){
            if(N[i]==0){
                Validatornodes[v].nodeid = id;
                Validatornodes[v].value = N[i];
                Validatornodes[v].clustergrpno = clusterno;
                Validatornodes[v].rating =0;
                Validatornodes[v].availability = true;
                Validatornodes[v].staker = false;
                v++;                     
            }
            else{
                Stakernodes[s].nodeid = id;
                Stakernodes[s].value = N[i];
                Stakernodes[s].clustergrpno = clusterno;
                Stakernodes[s].rating = 0;
                Stakernodes[s].availability = true;
                Stakernodes[s].staker = true;  
                s++;  
            }
            count++;
            if(count>9){ count=0; clusterno++;}
            id++;
       }
     }


    void selectNodeFromCluster(){
        count = 0; vcount = 0;

 	            int sum;
 	            sum=0;
                int clusterno;
                int selectednode;
                cout<<"Enter the cluster number from 0 to 9: ";
                cin>>clusterno;
                Node stakernodelist[10], validatornodelist[10];
                for(int i=0;i<65;i++){
                  if(Stakernodes[i].clustergrpno==clusterno){
                    stakernodelist[count] = Stakernodes[i];
                    count++;
                  }
                }
               
                   cout<< "\n Staker Nodes present in this cluster are: \n";
                for(int i=0;i<count;i++){
                  cout<< "\nStakerNode "<<i<<" :";
                  cout<< stakernodelist[i].nodeid<<"--";
                  cout<< stakernodelist[i].value<<"--";
                  cout<< stakernodelist[i].clustergrpno<<"-:)\n";
                  // cout<< stakernodelist[i].rating<<"]-";
                  //cout<< BoolToString(stakernodelist[i].availability)<<"-:) \n";

                }
                

               label:srand((int)time(0));
                int randno = rand() % clusters[clusterno][1] +1;
               
              for(int i=0; i<10;i++){
                    randno -= stakernodelist[i].value;
                      if(randno<=0){
                          selectednode = i;
                          break;
                          }
                      else{
                          continue;
                          }
                }

                 srand(time(NULL));
                 for(int i=0;i<35;i++){
                  if(Validatornodes[i].clustergrpno==clusterno){
                    sum+=(rand()%14-5);
                  }
                } 
                //    cout<< "\n Overall rating done by validators of this cluster: "<<sum<<"\n";                  
                 if(sum<0){
                      goto label;
                 }
                 stakernodelist[selectednode].rating = sum;

                cout<<"\n Selected node is as follows: \n"<<"NodeID: "<<stakernodelist[selectednode].nodeid<<"\nValue: "<<stakernodelist[selectednode].value<<"\nRating:"<<stakernodelist[selectednode].rating;
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
