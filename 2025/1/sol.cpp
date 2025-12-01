#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
  std::ifstream input_stream("input.txt");
  std::string line;

  int cur_pos = 50;
  int ans = 0;

  while (std::getline(input_stream, line)) {
    if (line.empty())
      continue;

    char dir = line[0];
    int rot = std::stoi(line.substr(1));

    if (dir == 'L') {
      cur_pos = (cur_pos - rot) % 100;
      if (cur_pos < 0)
        cur_pos += 100;
    } else { // 'R'
      cur_pos = (cur_pos + rot) % 100;
    }

    if (cur_pos == 0) {
      ++ans;
    }
  }

  std::cout << ans << "\n";
  input_stream.close();
}
