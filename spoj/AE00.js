// Test Case:  N = 10000 => 46884
// Test Case:  N = 6 => 8
// Test Case:  N = 5000 => 21723
var input = 10000; // 10000;
var nSquares = input;
var isPrime = true;
var nRect = 0;

while(nSquares)
{
	// Count all possible factors [ Rectangular Geometry Formation ]
	for(var i = 2; i <= Math.sqrt(nSquares); ++i) // Note: <=
	{
		if (nSquares % i === 0) {
			++nRect; // don't break count all factors
			// break;
		}
	}
	nSquares--;
}

console.log(input + nRect);





// Test Case:  N=10000 => 46884
/*
var input = 10000;
var nSquares = input;
var isPrime = true;
var nRect = 0;

while(nSquares > 3)
{
	if(!(nSquares % 2))
	{
		// even
		++nRect;
	}
	else
	{
		// odd
		// check is a prime number or not
		for(var i = 2; i < Math.sqrt(nSquares); ++i)
		{
			if (nSquares % i === 0) {
				isPrime = false;
				break; 
			} 
		}

		if(!isPrime)
			++nRect;
	}

	nSquares--;
}

console.log(input + nRect);
*/
