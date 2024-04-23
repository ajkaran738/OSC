#include<iostream>
#include<vector>
using namespace std;

void FCFS(vector<int> requests,int diskSize, int request_size,int headPosition){
    cout<<"FCFS Sequence : "<<headPosition<<"->"<<requests[0]<<"->";
    int TotalSeek = abs(headPosition - requests[0]);
    for(int i=0;i<request_size-1;i++){
        cout<<requests[i+1]<<"->";
        TotalSeek += abs(requests[i] - requests[i+1]);
    }

    cout<<"\nTotal Seek Time : "<<TotalSeek<<endl;
};

void SSTF(vector<int> requests,int diskSize, int request_size,int headPosition){
    vector<int> temp = requests;
    int TotalSeek = 0;
    int curr_head = headPosition;

    cout<<"SSTF Sequence : "<<headPosition<<"->";
    for(int i=0;i<request_size;i++){
        int min_distance = diskSize+1;
        int min_index = -1;

        for(int j=0;j<temp.size();j++){
            if(abs(temp[j] - curr_head) < min_distance){
                min_distance = abs(temp[j] - curr_head);
                min_index = j;
            }
        }

        TotalSeek += min_distance;
        cout<<temp[min_index]<<"->";
        curr_head = temp[min_index];
        temp.erase(temp.begin() + min_index);
    }

    cout<<endl;
    cout<<"Total  Seek Time : "<<TotalSeek<<endl;
};

int main()
{
    int diskSize;
    cout<<"Enter Disk Size : ";
    cin>>diskSize;
    int request_size;
    cout<<"Enter No of Requests : ";
    cin>>request_size;
    
    vector<int> requests(request_size);
    cout<<"Enter Requests : "<<endl;
    for(int i=0;i<request_size;i++){
        cin>>requests[i];
    }

    int headPosition;
    cout<<"Enter Head Position : ";
    cin>>headPosition;
    
    FCFS(requests,diskSize,request_size,headPosition);
    SSTF(requests,diskSize,request_size,headPosition);

    return 0;
}