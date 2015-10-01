void sortList(List &L, int condition) {
    switch(condition) {
        case 1: {
            bool blmselesai = true;
            address tmp;
            while(blmselesai) {
                blmselesai=false;
                address P=Next(First(L));
                while(Next(P)!=Next(First(L))) {
                    if(Info(P).ID<Info(Prev(P)).ID) {
                        address tmp=new elemenList;
                        Info(tmp)=Info(Prev(P));
                        Info(Prev(P))=Info(P);
                        Info(P)=Info(tmp);
                        blmselesai=true;
                    }
                    P=Next(P);
                }
            }
        }
        case 2: {
            bool blmselesai = true;
            address tmp;
            while(blmselesai) {
                blmselesai=false;
                address P=Next(First(L));
                while(Next(P)!=Next(First(L))) {
                    if(Info(P).name<Info(Prev(P)).name) {
                        address tmp=new elemenList;
                        Info(tmp)=Info(Prev(P));
                        Info(Prev(P))=Info(P);
                        Info(P)=Info(tmp);
                        blmselesai=true;
                    }
                    P=Next(P);
                }
            }
        }
    }
}
