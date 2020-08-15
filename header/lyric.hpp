_Pragma("once");
#include<meta_data.hpp>
#include<vector>
using std::vector;
namespace LyricS{
	/**
	 * @brief specify timing information in lyric
	*/
	struct LyricTime{
		unsigned int start_;		///< start moment in millisecond(ms)
		unsigned int duration_;		///< time that the target last for in millisecond(ms)
	};	// struct LyricTime
	
	/**
	 * @brief minimal unit in lyric with exact timming, usually a character or a word
	*/
	struct LyricLinePart{
		string 		content_;	///< actual content of part
		LyricTime	timming_;	///< timming information of part
	};	// struct LyricLinePart
	
	/**
	 * @brief line in lyric
	*/
	class LyricLine{
		private:
			/// meta data
			LyricLineMetaData					meta_data_;
			/// origin lyric parts
			vector<LyricLinePart>				origin_parts_;
			/// translated lyric parts: language code - parts
			map<string, vector<LyricLinePart>>	translated_parts_;
			/// timming infomation
			LyricTime							timming_;
	};	// class LyricLine
	
	/**
	 * @brief entire lyric
	*/
	class Lyric{
		private:
			/// meta data
			LyricMetaData		meta_data_;
			/// lyric lines
			vector<LyricLine>	lines_;
			/// timming information
			LyricTime			timming_;
	};	// class Lyric
}	// namespace LyricS