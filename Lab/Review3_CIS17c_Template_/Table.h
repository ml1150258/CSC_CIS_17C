template<class T>
class Table{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        Table(unsigned int,unsigned int);
        Table(const Table<T> &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};