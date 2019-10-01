/*
toioynnkpheleaigshareconhtomesnlewx
length = 35;
column = 5
row = 35 / 5 = 7
*/

/*
var num = '123456';
var row = 3;
var col = 2;
var i = 0;

var array2D = [[]];
for(var r = 0; r < row; ++r)
{
	array2D[r] = [];
	for(var c = 0; c < col; ++c)
	{
		array2D[r][c] = num[i++];
	}
}
console.log(array2D); 
// [[ '1', '2' ], 
//	[ '3', '4' ], 
//	[ '5', '6' ]]

console.log(array2D[2][1]); // 6
*/


var str = 'toioynnkpheleaigshareconhtomesnlewx';
var len = str.length;
var col = 5;
var row  = len / col;
var i = 0;
var mat = [[]]; // [row][col];
var r = 0, c = 0;
var result = '';

for(r = 0; r < row; ++r)
{
	mat[r] = [];

	if(r % 2)
	{
		// Right to Left read
		for(c = col-1; c > -1; --c)
		{
			mat[r][c] = str[i++];
		}
	}
	else
	{
		// Left to Right read (usual way)
		for(c = 0; c < col; ++c)
		{
			mat[r][c] = str[i++];
		}
	}
}

console.log(mat);

// Column wise read
for(c = 0; c < col; ++c)
{
	for(r = 0; r < row; ++r)
	{
		result += mat[r][c];
		
	}
}

console.log(result);


