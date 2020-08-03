_Pragma("once");
#include<map>
#include<string>
#include<vector>
using std::map;
using std::string;
using std::vector;
namespace LyricS{
	/**
	 * @brief specify timing information in lyric
	*/
	struct LyricTime{
		unsigned int start_;	///< start moment in millisecond(ms)
		unsigned int last_;		///< time that the target last for in millisecond(ms)
	};
	/**
	 * @brief minimal unit in lyric with exact timming, usually a character or a word
	*/
	struct LyricLinePart{
		string 		content_;	///< actual content of part
		LyricTime	timming_;	///< timming information of part
	};
	class LyricLine{
		private:
			/// meta data: key - value
			map<string, string>					meta_;
			/// origin lyric parts
			vector<LyricLinePart>				origin_parts_;
			/// translated lyric parts: language code - parts
			map<string, vector<LyricLinePart>>	translated_parts_;
			/// timming infomation
			LyricTime							timming_;
	};
}