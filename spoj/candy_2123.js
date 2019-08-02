// https://www.spoj.com/problems/CANDY/

function solveCase(lines)
{
	while(lines)
	{
		var nPackets = parseInt(lines.shift());
		if(nPackets === -1)
		{
			return;
		}

		var totalCandy = 0;
		var input = []; //  = [1,1,1,1,6];
		var i = 0;
		var move = 0;
		for(i = 0 ; i < nPackets; ++i)
		{
			input.push(parseInt(lines.shift()));
			totalCandy += input[i];
		}
		var avg = Math.ceil(totalCandy / nPackets);
		for(i = 0 ; i < nPackets; ++i)
		{
			if(input[i] > avg)
			{
				move += input[i] - avg;
			}
		}
		console.log(move ? move : -1);
	}
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Method 1:
// var fs = require('fs');
// var content = fs.readFileSync('C:\/Users\/irobot\/Documents\/GitHub\/codingContest\/help\/small.txt', 'utf8');
// var lines = content.split('\r\n');

// Method 2:
var readline = require('readline');
var rl = readline.createInterface({
	// input: require('fs').createReadStream('C:\/Users\/irobot\/Documents\/GitHub\/codingContest\/help\/small.txt'),
	input: process.stdin,
	output: process.stdout,
	terminal: false
});

var n = 0;
var i = -1;
var content = [];
rl.on('line', function (line) {
	if(n === i)
	{
		solveCase(content, n);
	}
	if(n === 0)
	{
		n = parseInt(line);
	}
	else
	{
		content[++i] = parseInt(line);
	}
	
	
});


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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