#ifndef THREAD_H_INCLUDED
#define THREAD_H_INCLUDED

class thread
{
    public:
    int i;
    int j;
    int numb;
    std::vector <std::vector<int> > arr;

    thread ()
    {
        arr.resize(9);
        for (unsigned i = 0; i < arr.size(); i++) arr[i].resize(9);
    }
};

#endif // THREAD_H_INCLUDED
