#ifndef ODATA_FILESYSTEMNODE_H_
#define ODATA_FILESYSTEMNODE_H_

#include <iosfwd>
#include <list>
#include <memory>

namespace OData {

class FileSystemNode {
public:
  FileSystemNode() = default;
  virtual ~FileSystemNode() = default;
  FileSystemNode(const FileSystemNode&) = delete;
  FileSystemNode& operator=(const FileSystemNode&) = delete;
  bool operator==(const FileSystemNode& node) const;
  bool operator!=(const FileSystemNode& node) const;

  virtual void toString(std::ostream& ostr, unsigned indent_level = 0) const
      noexcept = 0;
  virtual bool compare(const FileSystemNode& node) const noexcept = 0;
  virtual std::string getName() const noexcept = 0;
  virtual FileSystemNode* getFile(std::list<std::string> path) const
      noexcept = 0;

  FileSystemNode* getFile(const std::string& file) const noexcept;
  static std::ostream& indent(std::ostream& ostr, unsigned level);
};

std::ostream& operator<<(
    std::ostream& ostr, const FileSystemNode& node) noexcept;

} /* namespace OData */

#endif /* ODATA_FILESYSTEMNODE_H_ */
