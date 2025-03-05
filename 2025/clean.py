
import os
import argparse

def get_files_to_delete(root_path):
    extensions = {'.py', '.pyc', '.pyo', '.pyd', '.c', '.h', '.cpp', '.hpp', '.cc'}
    files_to_delete = []

    for dirpath, _, filenames in os.walk(root_path):
        for file in filenames:
            if not any(file.endswith(ext) for ext in extensions):
                files_to_delete.append(os.path.join(dirpath, file))

    return files_to_delete

def main():
    print("Cleaning project")

    parser = argparse.ArgumentParser(description='Scan and delete non-python/c/cpp files.')
    parser.add_argument('path', nargs='?', default='.', type=str, help='The root path to start scanning.')
    args = parser.parse_args()

    root_path = args.path
    files_to_delete = get_files_to_delete(root_path)

    print("The following files will be deleted:")
    for file in files_to_delete:
        print(file)

    skip_confirmation = True
    if skip_confirmation != True:
        confirmation = input("Do you want to delete these files? (yes/no): ")
    else:
        confirmation = "yes"
    
    if confirmation.lower() == 'yes':
        for file in files_to_delete:
            os.remove(file)
        print("Files deleted.")
    else:
        print("Operation cancelled.")

if __name__ == "__main__":
    main()
