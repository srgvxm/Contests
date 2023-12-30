#include <iostream>
#include "json.hpp"
#include "fstream"

using namespace std;
using json = nlohmann::json;

int main() {
  int ID, sums = 0;
  cin >> ID;
  ifstream f("data.json");
  json data = json::parse(f);
  for (auto i : data) {
    for (auto j : i["tasks"]) {
      if (j["user_id"] == ID and j["completed"]) {
        sums += 1;
      }
    }
  }
  cout << sums;
}