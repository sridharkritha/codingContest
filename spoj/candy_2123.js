// https://www.spoj.com/problems/CANDY/
/*
Input file:
5
1
1
1
1
6
2
3
4
-1

Output file:
4
-1
*/

var nPackets = 5;
var totalCandy = 0;
var input = [1,1,1,1,6];
var i = 0;
var move = 0;
for(i = 0 ; i < nPackets; ++i)
{
	totalCandy += input[i];
}
var avg = Math.ceil(totalCandy / nPackets);
for(i = 0 ; i < nPackets; ++i)
{
	if(input[i] > avg)
	{
		move += input[i] - avg;
	}
	// totalCandy += input[i];
}

console.log(move ? move : -1);