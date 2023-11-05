// check if K-th bit is set or not:

void isKthBitSet(int n, int k)
{
    if (n & (1 << k))
        cout << "SET";
    else
        cout << "NOT SET";
}


// change the K-th bit 0 to 1 or vice-versa:

ll changebit(int number, int k){
    number^=(1<<k);
}