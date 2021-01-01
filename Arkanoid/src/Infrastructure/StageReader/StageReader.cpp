#include "StageReader.h"

namespace Arkanoid {
	std::vector<BrickDto> StageReader::GetBrickSetup(int stageId)
	{
		std::vector<BrickDto> bricks;

		try
		{
			std::fstream file;
			file.open(this->_path + std::to_string(stageId) + ".dat", std::ios_base::in);
			std::string line;

			for (short h = 0; h < this->MaxHeight; h++)
			{
				std::string line;
				std::getline(file, line);
				for (short w = 0; w < this->MaxWidth; w++)
				{
					BrickDto dto;
					if (w < line.length())
					{
						dto.BrickStateId = line[w] - '0';
						dto.PosY = h;
						dto.PosX = w;
					}

					bricks.push_back(dto);
				}
			}
		}
		catch (std::ifstream::failure e) {
			std::cout << "Error while reading a file. StageId: " << stageId << std::endl;
		}
		catch (std::invalid_argument e) {
			std::cout << "Cannot read type of block. StageId: " << stageId << std::endl;
		}
		return bricks;
	}
	short StageReader::GetTotalStagesCount()
	{
		short count = 0;
		for (const auto& entry : std::filesystem::directory_iterator(this->_path))
		{
			if (entry.path().extension() == ".dat")
				count++;
		}
		return count;
	}
}

