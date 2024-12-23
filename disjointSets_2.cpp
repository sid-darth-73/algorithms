template <class T>
class DisjointSetDS{
  unordered_map<T, T> parent;
  // set repr to <set size, set rank> 
  unordered_map<T, pair<int, int>> representativeToSetSpecs;
public:
  void makeSet(T e){
    parent[e] = e;
    representativeToSetSpecs[e] = {1, 0};
  }
 
  void unionSet(T e1, T e2) {
    T repE1 = find(e1);
    T repE2 = find(e2);
 
    if(repE1 == repE2){
      return;
    }
 
    int rankS1 = representativeToSetSpecs[repE1].second;
    int rankS2 = representativeToSetSpecs[repE2].second;
 
    if(rankS1 > rankS2){
      parent[repE2] = repE1;
      representativeToSetSpecs[repE1].first += 
              representativeToSetSpecs[repE2].first;
      representativeToSetSpecs.erase(repE2);
    }
 
    else {
      parent[repE1] = repE2;
      representativeToSetSpecs[repE2].first += 
              representativeToSetSpecs[repE1].first;
      if(rankS1 == rankS2)
        representativeToSetSpecs[repE2].second++;
      representativeToSetSpecs.erase(repE1);
    }
  }
 
  T find(T e) {
    if(parent[e] == e)
      return e;
    return parent[e] = find(parent[e]);
  }
 
  int sizeOfSet(T e){
    T rep = find(e);
    return representativeToSetSpecs[rep].first;
  }
};