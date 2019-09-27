#if 1
// Not working - check it
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	unsigned int nPackets = 0;
	signed int  totalCandy = 0;
	unsigned int i = 0, c = 0;
	unsigned int move = 0;	
	double average = 0.0;
	vector<unsigned int> v;
	vector<int> output;

	while(true)
	{
		nPackets = 0;
		totalCandy = 0;
		i = 0;
		c = 0;
		move = 0;
		average = 0;
		v.clear();

		cin>> nPackets;

		if(nPackets == -1) 
		{
			for(i = 0 ; i < output.size(); ++i)
			{
				cout<< output[i] << endl;
			}
			break;
		}

		for(i = 0 ; i < nPackets; ++i)
		{
			cin>> c;
			v.push_back(c);
			totalCandy += c;
		}

		// average = double(totalCandy) / nPackets;
		//unsigned int avg = ceil(average);
		unsigned int avg = totalCandy / nPackets;

		for(i = 0 ; i < nPackets; ++i)
		{
			if(v[i] < avg)   // v[i] > avg
			{
				move += avg - v[i];  // move += v[i] - avg;
			}
		}

		output.push_back(move ? move : -1);
	}

	return 0;
}

#else

// working 

#include <iostream>

using namespace std;
int n,a[10000], ans[10000],j=0,i;

 int getMoves(int candy[],int l)
 {
     int sum=0,moves=0;
     for(int x=0; x<l; x++)
     	sum = sum + candy[x];

     if (sum%l !=0)
     	return -1;

     else
     {
         int avg = sum/l;
         for(int x=0;x<l;x++){
             if(candy[x]<avg)
             	moves = moves + (avg-candy[x]); }
     }
     return moves;
 }
 
int main()
{

    while(1) {
        cin>>n;
        if(n == -1){
            for (i=0; i<j; i++) 
                cout<<ans[i]<<endl;
                break; }

        for(i = 0; i<n ; i++)
            cin>>a[i];
        ans[j] = getMoves(a,n);
        j++;
    }
    return 0;
}

#endif
