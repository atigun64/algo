struct LSGT{
  vector<int> t, lt;
  int n;
  LSGT(){}
  LSGT(int _n) : n(1){
    while(n < _n) n*= 2;
    t.assign(n*2+5, 0);
    lt.assign(2*n+5, 0);
  }
  void upd(int v, int l, int r, int ql, int qr, int d){
    if(r <=qr && l >= ql){
      t[v]+= d, lt[v]+= d;
      return;
    }
    if(r < ql || l > qr)return;
    int mid=(l+r)/2;
    push(v, l, r, mid);
    upd(v*2, l, mid, ql, qr, d), upd(v*2+1, mid+1, r, ql, qr, d);
    t[v]=merge(t[v*2], t[v*2+1]);
  }
  void upd(int ql, int qr, int d){upd(1, 0, n, ql, qr, d);}
  int get(int v, int l, int r, int ql, int qr){
    if(r <= qr && l >= ql) return t[v];
    if(r < ql || l > qr) return 1e9;
    int mid=(l+r)/2;
    push(v, l, r, mid);
    return merge(get(v*2, l, mid, ql, qr), get(v*2+1, mid+1, r, ql, qr));
  }
  int get(int ql, int qr){return get(1, 0, n, ql, qr);}
  int merge(int x, int y){return min(x, y);} // min or max
  void push(int v, int l, int r, int mid){
    t[v*2]+= lt[v], t[v*2+1]+= lt[v];
    lt[v*2]+= lt[v], lt[v*2+1]+= lt[v];
    lt[v]=0;
  }
};
