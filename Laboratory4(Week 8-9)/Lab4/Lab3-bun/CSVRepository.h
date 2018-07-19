#pragma once
#include "IFileRepository.h"

// Comma Separate Value - repository -> writes and reads to a text file in CSV format
class CSVRepository : public IFileRepository {
protected:
	void repoFromFile() override;
	void repoToFile() override;

public:

	CSVRepository(const std::string& source);
	~CSVRepository();
	void display() override;
};