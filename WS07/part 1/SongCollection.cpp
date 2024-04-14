#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <numeric>
#include "SongCollection.h"

namespace seneca
{
	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << "| " << std::left << std::setw(20) << theSong.m_title
			<< " | " << std::left << std::setw(15) << theSong.m_artist
			<< " | " << std::left << std::setw(20) << theSong.m_album
			<< " | " << std::right << std::setw(6) << (theSong.m_year > 0 ? std::to_string(theSong.m_year) : "")
			<< " | " << theSong.m_length / 60 << ":" << std::setw(2) << std::setfill('0') << theSong.m_length % 60
			<< " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |"
			<< std::setfill(' ');
		return out;
	}

	SongCollection::SongCollection(const std::string& filename)
	{
		std::ifstream file(filename);
		if (!file)
			throw "Invalid filename!";

		while (file)
		{
			Song song;
			std::string buffer;
			std::getline(file, buffer);
			if (file)
			{
				trim(song.m_title = buffer.substr(0, 25));
				trim(song.m_artist = buffer.substr(25, 25));
				trim(song.m_album = buffer.substr(50, 25));
				try
				{
					song.m_year = std::stoi(buffer.substr(75, 5));
				}
				catch (...)
				{
					song.m_year = 0;
				}
				song.m_length = std::stoi(buffer.substr(80, 5));
				song.m_price = std::stod(buffer.substr(85));
				this->m_songs.push_back(song);
			}
		}
		file.close();
	}

	std::string& SongCollection::trim(std::string& token)
	{
		while (token.length() > 0 && token[0] == ' ')
			token.erase(0, 1);
		while (token.length() > 0 && token[token.length() - 1] == ' ')
			token.erase(token.length() - 1, 1);
		return token;
	}

	void SongCollection::display(std::ostream& out) const
	{
		std::for_each(m_songs.begin(), m_songs.end(), [&out](const Song& item) { out << item << std::endl; });
	}
}
