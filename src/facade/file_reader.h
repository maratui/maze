#ifndef A1_MAZE_FACADE_FILE_READER_H_
#define A1_MAZE_FACADE_FILE_READER_H_

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace s21 {
class FileReader {
 public:
  void ReadMazeFile(std::vector<std::vector<unsigned>> &vertical_walls,
                    std::vector<std::vector<unsigned>> &horizontal_walls,
                    const std::string &path);

  void WriteMazeToFile(
      const std::vector<std::vector<unsigned>> &vertical_walls,
      const std::vector<std::vector<unsigned>> &horizontal_walls,
      const std::string &path);

 private:
  void ReadRawsCols(unsigned &raws, unsigned &cols, std::ifstream &in);
  void ReadUnsignedMatrix(std::vector<std::vector<unsigned>> &unsigned_matrix,
                          unsigned raws, unsigned cols, std::ifstream &in);
  unsigned GetUnsignedFromLine(std::istringstream &line_iss);
  void WriteUnsignedMatrix(
      const std::vector<std::vector<unsigned>> &unsigned_matrix, unsigned raws,
      unsigned cols, std::ofstream &out);
};
}  // namespace s21

#endif  // A1_MAZE_FACADE_FILE_READER_H_
