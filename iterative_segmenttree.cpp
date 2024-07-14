template<typename T>
struct SGT{
  vector<T> t;
  int n;
  T empty;
  function<T(const T&, const T&)> merge;
  void resize(int nn, T ee, function<T(const T&, const T&)> mm){
    empty=ee, merge=mm;
    n=1;
    while(n < _n){n*= 2;}
    t.assign(2*n, empty);
  }
  void upd(int I, T X){
    for(t[I+= n]=X; I/2; I/= 2)
      t[I/2]=merge(t[I], t[I^1]);
  }
  void add(int I, T X){
    for(t[I+= n]+= X; I/2; I/= 2)
      t[I/2]=merge(t[I], t[I^1]);
  }
  void minimize(int I, T X){
    for(t[I+=n]=min(t[I], X); I/2; I/= 2)
      t[I/2]=merge(t[I], t[I^1]);
  } 
  void maximize(int I, T X){
    for(t[I+=n]=max(t[I], X); I/2; I/= 2)
      t[I/2]=merge(t[I], t[I^1]);
  }
  T get(int L, int R){
    ll ans=empty;
    for(L+=n, R+=n; L<=R; L>>=1, R>>=1){
      if(L&1) ans=merge(ans, t[L++]);
      if(!(R&1)) ans=merge(ans, t[R--]);
    }
    return ans;
  }
};
