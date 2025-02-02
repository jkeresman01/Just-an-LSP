#pragma once

#include <mutex>
#include <string>
#include <unordered_map>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// Typedefs
///
//////////////////////////////////////////////////////////////
typedef std::unordered_map<std::string, std::string> PropertiesT;

//////////////////////////////////////////////////////////////
///
/// @class ConfigurationManager
///
/// @brief Implementation of configuration manager for JustAnLSP
///
//////////////////////////////////////////////////////////////
class ConfigurationManager
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructors (default, copy, move)
    ///        and assignment operators
    ///
    //////////////////////////////////////////////////////////////
    ConfigurationManager(const ConfigurationManager &) = delete;
    ConfigurationManager(ConfigurationManager &&) = delete;
    ConfigurationManager &operator=(const ConfigurationManager &) = delete;
    ConfigurationManager &operator=(ConfigurationManager &&) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Destructor, cleans up resources
    ///
    //////////////////////////////////////////////////////////////
    ~ConfigurationManager();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Load configuration from the XML file
    ///
    //////////////////////////////////////////////////////////////
    void load();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Get the Singleton instance of ConfigurationManager
    ///
    /// @return Pointer to the single instance of ConfigurationManager
    ///
    //////////////////////////////////////////////////////////////
    static ConfigurationManager *getInstance();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieve a property value by its key
    ///
    /// @param key The key of the property to retrieve
    /// @return The value associated with the given key
    ///
    //////////////////////////////////////////////////////////////
    std::string getProperty(const std::string &key);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Private constructor
    ///
    /// Ensures that the class can only be instantiated through
    /// the `getInstance` method.
    ///
    //////////////////////////////////////////////////////////////
    ConfigurationManager() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Helper function to load properties from a file stream
    ///
    /// @param in Reference to an input file stream
    ///
    //////////////////////////////////////////////////////////////
    void load(std::ifstream &in);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Pointer to the singleton instance
    ///
    //////////////////////////////////////////////////////////////
    static ConfigurationManager *s_instance;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutex to ensure thread safety
    ///
    //////////////////////////////////////////////////////////////
    static std::mutex s_mutex;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Path to the XML configuration file
    ///
    //////////////////////////////////////////////////////////////
    const char *XML_CONFIGURATION_PATH = "../../config/config.xml";

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Unordered map to store key-value pairs from the configuration file
    ///
    //////////////////////////////////////////////////////////////
    PropertiesT m_properties;
};
} // namespace justanlsp
