#include <bits/stdc++.h>

using namespace std;

#define SMAX 32
#define CMAX 100100

int names;
map <string,int> name2id;
vector <string> id2name;

int cities;
map <string,int> city2id;
vector <string> id2city;

map < int, vector< pair<int,int> > > events;

int maybe_new_city(string city) {
  if (city2id.find(city) == city2id.end()) {
    city2id[city] = cities++;
    id2city.push_back(city);
  }
  return city2id[city];
}

long long citymoney[CMAX];

struct cool_city {
  int id;
  bool operator < (const cool_city &o) const {
    if (citymoney[id] != citymoney[o.id]) {
      return citymoney[id] > citymoney[o.id];
    }
    return id < o.id;
  }
};

int main() {
  cities = 0;

  scanf("%d", &names);
  int cur[names];
  long long money[names];
  for (int i = 0; i < names; i++) {
    char name[SMAX], city[SMAX];
    scanf("%s %s %lld", name, city, &money[i]);
    name2id[name] = i;
    id2name.push_back(name);
    cur[i] = maybe_new_city(city);
  }

  int m, k;
  scanf("%d %d", &m, &k);
  for (int i = 0; i < k; i++) {
    int day;
    char name[SMAX], city[SMAX];
    scanf("%d %s %s", &day, name, city);
    day--;
    int city_id = maybe_new_city(city);
    int name_id = name2id[name];
    events[day].push_back(make_pair(name_id, city_id));
  }

  if (cities == 1) {
    printf("%s %d\n", id2city[0].c_str(), m);
    return 0;
  }

  memset(citymoney, 0, sizeof(citymoney));

  set <cool_city> S;
  for (int i = 0; i < cities; i++) {
    S.insert((cool_city) {i});
  }

  for (int i = 0; i < names; i++) {
    cool_city city = (cool_city) { cur[i] };
    S.erase(city);
    citymoney[city.id] += money[i];
    S.insert(city);
  }

  map <string,int> days;

  for (int i = 0; i < m; i++) {
    set<cool_city>::iterator first = S.begin();
    set<cool_city>::iterator second = ++S.begin();
    if (citymoney[first->id] > citymoney[second->id]) {
      days[id2city[first->id]]++;
    }

    for (int j = 0; j < events[i].size(); j++) {
      pair <int,int> event = events[i][j];
      int name_id = event.first;
      int city_id = event.second;

      cool_city old_city = (cool_city) { cur[name_id] };

      S.erase(old_city);
      citymoney[old_city.id] -= money[name_id];
      S.insert(old_city);

      cool_city new_city = (cool_city) { city_id };

      S.erase(new_city);
      citymoney[new_city.id] += money[name_id];
      S.insert(new_city);

      cur[name_id] = city_id;
    }
  }

  for (map<string,int>::iterator it = days.begin(); it != days.end(); it++) {
    printf("%s %d\n", it->first.c_str(), it->second);
  }

  return 0;
}
