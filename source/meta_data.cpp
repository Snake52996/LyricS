#include<meta_data.hpp>
#include<stdexcept>
namespace LyricS{
	const bool MetaData::defined(const MetaDataId& key)const{
		if(!this->isIdValid(key)) throw std::out_of_range("Invalid key");
		return official_data_.count(key) == 1;
	}
	const bool MetaData::defined(const string& key)const{
		return user_defined_data_.count(key) == 1;
	}
	const string& MetaData::get(const MetaDataId& key)const{
		try{
			if(defined(key)) return official_data_.find(key)->second;
		}catch(std::out_of_range& e){
			throw;
		}
		throw std::runtime_error("Does not exist");
	}
	const string& MetaData::get(const string& key)const{
		if(defined(key)) return user_defined_data_.find(key)->second;
		throw std::runtime_error("Does not exist");
	}
	const bool MetaData::set(const MetaDataId& key, const string& value){
		if(!this->isIdValid(key)) throw std::out_of_range("Invalid key");
		return official_data_.insert(make_pair(key, value)).second;
	}
	const bool MetaData::set(const string& key, const string& value){
		return user_defined_data_.insert(make_pair(key, value)).second;
	}
	void MetaData::forcedSet(const MetaDataId& key, const string& value){
		if(!this->isIdValid(key)) throw std::out_of_range("Invalid key");
		official_data_.insert_or_assign(key, value);
	}
	void MetaData::forcedSet(const string& key, const string& value){
		user_defined_data_.insert_or_assign(key, value);
	}
	
	const bool LyricMetaData::isIdValid(const MetaDataId& key)const noexcept{
		return key > MetaDataId::BEGIN_LYRIC_METADATA_ID && key < CURRENT_LYRIC_METADATA_ID_LIMIT;
	}
	
	const bool LyricLineMetaData::isIdValid(const MetaDataId& key)const noexcept{
		return key > MetaDataId::BEGIN_LYRIC_LINE_METADATA_ID && key < CURRENT_LYRIC_LINE_METADATA_ID_LIMIT;
	}
}	//namespace LyricS