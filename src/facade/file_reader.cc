#include "file_reader.h"

using namespace s21;

void FileReader::ReadMazeFile(
    std::vector<std::vector<unsigned>> &vertical_walls,
    std::vector<std::vector<unsigned>> &horizontal_walls,
    const std::string &path) {
  std::ifstream in(path);

  vertical_walls.clear();
  horizontal_walls.clear();

  if (in.is_open()) {
    std::string line = "";
    unsigned raws = 0U;
    unsigned cols = 0U;

    ReadRawsCols(raws, cols, in);
    ReadUnsignedMatrix(vertical_walls, raws, cols, in);
    if (std::getline(in, line)) {
      ReadUnsignedMatrix(horizontal_walls, raws, cols, in);
    }
  }
  in.close();
}

void FileReader::WriteMazeToFile(
    const std::vector<std::vector<unsigned>> &vertical_walls,
    const std::vector<std::vector<unsigned>> &horizontal_walls,
    const std::string &path) {
  unsigned raws = vertical_walls.size();

  if (raws > 0U) {
    unsigned cols = vertical_walls[0].size();

    if (cols > 0U) {
      std::ofstream out(path);

      if (out.is_open()) {
        out << raws << " " << cols << "\n";
        WriteUnsignedMatrix(vertical_walls, raws, cols, out);
        out << '\n';
        WriteUnsignedMatrix(horizontal_walls, raws, cols, out);
      }
      out.close();
    }
  }
}

void FileReader::ReadRawsCols(unsigned &raws, unsigned &cols,
                              std::ifstream &in) {
  std::string line = "";

  if (std::getline(in, line)) {
    std::istringstream line_iss(line);

    raws = GetUnsignedFromLine(line_iss);
    cols = GetUnsignedFromLine(line_iss);
  }
}

void FileReader::ReadUnsignedMatrix(
    std::vector<std::vector<unsigned>> &unsigned_matrix, unsigned raws,
    unsigned cols, std::ifstream &in) {
  std::string line = "";

  unsigned_matrix.clear();
  for (auto i = 0U; (i < raws) && (std::getline(in, line)); i++) {
    std::istringstream line_iss(line);
    std::vector<unsigned> unsigned_vector;

    for (auto j = 0U; j < cols; j++) {
      unsigned_vector.push_back(GetUnsignedFromLine(line_iss));
    }
    unsigned_matrix.push_back(unsigned_vector);
  }
}

unsigned FileReader::GetUnsignedFromLine(std::istringstream &line_iss) {
  std::string num_str = "";
  unsigned unsigned_num = 0;

  if (std::getline(line_iss, num_str, ' ')) {
    std::istringstream num_str_iss(num_str);

    num_str_iss >> unsigned_num;
  }

  return unsigned_num;
}

void FileReader::WriteUnsignedMatrix(
    const std::vector<std::vector<unsigned>> &unsigned_matrix, unsigned rows,
    unsigned cols, std::ofstream &out) {
  for (auto i = 0U; i < rows; i++) {
    for (auto j = 0U; j < cols; j++) {
      out << unsigned_matrix[i][j] << ' ';
    }
    out << '\n';
  }
}
