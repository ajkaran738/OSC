#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

void pageFIFO(int seq[],int frames,int n){
    list<int> queue(frames, -1);
    int page_fault = 0;
    for(int i=0;i<n;i++){
        if(find(queue.begin(), queue.end(), seq[i]) == queue.end())
        {
            page_fault++;
            queue.pop_front();
            queue.push_back(seq[i]);
        }
    }
    cout<<"Page Faults (FIFO) : "<<page_fault<<endl;
}

void pageLRU(int seq[], int frames, int n) {
    vector<int> block(frames, -1); // Vector to represent memory blocks with initial value -1 (indicating empty)
    vector<int> block_uses(frames, 0); // Vector to track the last usage of each memory block, initialized to 0

    int page_faults = 0; // Counter to count page faults

    for(int i = 0; i < n; i++) { // Iterate over each page request
        auto found_at = find(block.begin(), block.end(), seq[i]); // Search for the page in memory

        if(found_at != block.end()) { // Page found in memory
            block_uses[found_at - block.begin()] = i; // Update the last usage of the block
        } else { // Page not found in memory
            page_faults++; // Increment page fault counter
            auto min_it = min_element(block_uses.begin(), block_uses.end()); // Find the least recently used block
            int min_index = min_it - block_uses.begin(); // Get the index of the least recently used block
            block[min_index] = seq[i]; // Replace the least recently used block with the current page
            block_uses[min_index] = i; // Update the last usage of the block
        }
    }

    cout << "Page Faults (LRU): " << page_faults; // Output the total number of page faults
};

int main(){
    int n;
    cout<<"Enter length of the Sequence : ";
    cin>>n;
    int seq[n];
    cout<<"Enter Page Sequence : \n";
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }

    int frames;
    cout<<"Enter No of Frames : ";
    cin>>frames;

    pageFIFO(seq,frames,n);
    pageLRU(seq,frames,n);

    return 0;
}

