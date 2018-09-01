#pragma once
#include "IFileRepository.h"

class CSVRepository : public IFileRepository {
protected:
	void repoFromFile() override;
	void repoToFile() override;

public:

	CSVRepository(const std::string& source);
	~CSVRepository();
	void display() override;
};