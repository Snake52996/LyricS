_Pragma("once");
namespace LyricS{
	/**
	 * @brief keys available for official supported meta data
	*/
	/*
	 * Keys are supposed to be unsigned and occupy 4 bytes therefore with value available
	 * from 0x0 to 0xffffffff.
	 *
	 * 65534 keys allocated for general usage, from 0x1 to 0xfffe,
	 * barriered with 0x0 and 0xffff;
	 * 65534 keys allocated to lyric meta data, from 0x10001 to 0x1fffe,
	 * barriered with 0x10000 and 0x1ffff;
	 * 65534 keys allocated to lyric line meta data, from 0x20001 to 0x2fffe,
	 * barriered with 0x20000 and 0x2ffff;
	 *
	 * Keys for general usage shall never be used to save values
	 *
	 * Only defined keys should be used.
	*/
	enum class MetaDataId: unsigned int{
		BEGIN_GENERAL_METADATA_ID = 0x0,
		CURRENT_GENERAL_METADATA_ID_LIMIT,
		END_GENERAL_METADATA_ID = 0xffff,
		BEGIN_LYRIC_METADATA_ID = 0x10000,
		L_ALBUM,
		L_ARTIST,
		L_CREATOR,
		L_BUILDER,
		L_TITLE,
		L_OFFSET,
		CURRENT_LYRIC_METADATA_ID_LIMIT,
		END_LYRIC_METADATA_ID = 0x1ffff,
		BEGIN_LYRIC_LINE_METADATA_ID = 0x20000,
		CURRENT_LYRIC_LINE_METADATA_ID_LIMIT,
		END_LYRIC_LINE_METADATA_ID = 0x2ffff
	};	// enum class MetaDataId
	
	// Static asserts to prevent meta data id from getting out of range
	static_assert(MetaDataId::CURRENT_GENERAL_METADATA_ID_LIMIT <= MetaDataId::END_GENERAL_METADATA_ID);
	static_assert(MetaDataId::CURRENT_LYRIC_METADATA_ID_LIMIT <= MetaDataId::END_LYRIC_METADATA_ID);
	static_assert(MetaDataId::CURRENT_LYRIC_LINE_METADATA_ID_LIMIT <= MetaDataId::END_LYRIC_LINE_METADATA_ID);
}	// namespace LyricS