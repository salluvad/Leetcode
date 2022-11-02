// minimum swaps to make binary string alternating
int minSwaps(string s)
{
    // init counter vars
    int countZero = 0, countOne = 0;

    // count '0' and '1'
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            countZero++;
        else
            countOne++;
    }

    // if counts differ by 1 or more => not possible
    if (countOne - countZero > 1 || countZero - countOne > 1)
        return -1;

    // init possible string vars:
    string strZero = "", strOne = "";

    // make all possible strings
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
        {
            strZero.push_back('0');
            strOne.push_back('1');
        }
        else
        {
            strZero.push_back('1');
            strOne.push_back('0');
        }
    }

    // init swap counter for zero and one
    int swapCountOne = 0, swapCountZero = 0;

    // if count of '0' and '1' are equal
    if (countZero == countOne)
    {
        // the given s should be of form strZero or strOne
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != strZero[i])
                swapCountOne++;
            if (s[i] != strOne[i])
                swapCountZero++;
        }

        // actual swap = swapCount/2
        return min(swapCountOne / 2, swapCountZero / 2);
    }
    // if countOne > countZero
    else if (countOne > countZero)
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] != strOne[i])
                swapCountOne++;
        return swapCountOne / 2;
    }
    // if countOne < countZero
    else
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] != strZero[i])
                swapCountZero++;
        return swapCountZero / 2;
    }

    // avoid warning
    return -1;
}
