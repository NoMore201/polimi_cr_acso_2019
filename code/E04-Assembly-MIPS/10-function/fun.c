int main( void )
{
	int a = leaf( 1, 2, 3, 4 );
}

int leaf( int g, int h, int i, int j )
{
	int f;
	
	f = (g + h) - (i + j);
	f = multiplier(f);
	return f;
}

int multiplier( int x ) {
	return x * 4;
}

