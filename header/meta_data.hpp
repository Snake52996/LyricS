_Pragma("once");
#include<meta_data_id.hpp>
#include<map>
#include<string>
using std::map;
using std::string;
namespace LyricS{
	class MetaData{
		protected:
			/// officially supported meta data
			map<MetaDataId, string>		official_data_;
			/// user-defined meta data
			map<string, string>			user_defined_data_;
			/**
			 * @brief verify if the officially supported key exists in current scope
			 * @param[in] MetaDataId key to verify
			 * @retval true if exists
			 * @retval false otherwise
			*/
			virtual const bool isIdValid(const MetaDataId&)const noexcept = 0;
		public:
			/**
			 * @brief query if a officially supported key exists
			 * @param[in] MetaDataId key to query
			 * @retval true if exists
			 * @retval false otherwise
			 * @exception std::out_of_range in case key is not valid
			*/
			const bool defined(const MetaDataId&)const;
			/**
			 * @brief query if a user-defined key exists
			 * @param[in] string key to query
			 * @retval true if exists
			 * @retval false otherwise
			*/
			const bool defined(const string&)const;
			/**
			 * @brief get officially supported meta data with a key
			 * @param[in] MetaDataId key
			 * @return data associated with the key
			 * @exception std::out_of_range in case key is not valid
			 * @exception std::runtime_error in case key does not exist
			*/
			const string& get(const MetaDataId&)const;
			/**
			 * @brief get user-defined meta data with a key
			 * @param[in] string key
			 * @return data associated with the key
			 * @exception std::runtime_error in case key does not exist
			*/
			const string& get(const string&)const;
			/**
			 * @brief set officially supported meta data with a key
			 * @param[in] MetaDataId key
			 * @param[in] string value
			 * @retval true if meta data set successfully
			 * @retval false otherwise
			 * @exception std::out_of_range in case key is not valid
			 * @note strong exception guarantee
			 * @remark setting value to existing key in meta data shall be frequent reason causing failure
			*/
			const bool set(const MetaDataId&, const string&);
			/**
			 * @brief set user-defined meta data with a key
			 * @param[in] string key
			 * @param[in] string value
			 * @retval true if meta data set successfully
			 * @retval false otherwise
			 * @remark setting value to existing key in meta data shall be frequent reason causing failure
			*/
			const bool set(const string&, const string&);
			/**
			 * @brief set officially supported meta data with a key
			 *        replace currently existing value in case specified key already exists
			 * @param[in] MetaDataId key
			 * @param[in] string value
			 * @exception std::out_of_range in case key is not valid
			 * @note setting always success if no exception thrown
			*/
			void forcedSet(const MetaDataId&, const string&);
			/**
			 * @brief set user-defined meta data with a key
			 *        replace currently existing value in case specified key already exists
			 * @param[in] string key
			 * @param[in] string value
			 * @note setting always success if no exception thrown
			*/
			void forcedSet(const string&, const string&);
			virtual ~MetaData() = 0;
	};	// class MetaData
	class LyricMetaData: public MetaData{
		protected:
			const bool isIdValid(const MetaDataId&)const noexcept;
	};	// class LyricMetaData
	class LyricLineMetaData: public MetaData{
		protected:
			const bool isIdValid(const MetaDataId&)const noexcept;
	};	// class LyricLineMetaData
}	// namespace LyricS