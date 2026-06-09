import os
import re
import sys

new_license_lines = [
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
            end_idx = i
            
    # Try to find the exact end lines common in ONLYOFFICE headers
    for i in range(start_idx, min(len(lines), start_idx + 50)):
        if "legalcode" in lines[i]:
            end_idx = i

    if end_idx == -1:
        # Fallback to agpl link
        for i in range(start_idx, min(len(lines), start_idx + 50)):
            if "agpl-3.0.html" in lines[i]:
                end_idx = i

    if end_idx == -1:
        return False

    # Search forwards for the end of the block
    block_end = end_idx
    for i in range(end_idx + 1, min(len(lines), end_idx + 15)):
        if re.match(r'^[\s/*#\'\-<!REM]*$', lines[i]):
            if any(c in lines[i] for c in ['*', '#', '!', '-']):
                block_end = i
            else:
                break
        elif "*****************" in lines[i] or "#################" in lines[i]:
            block_end = i
        else:
            break

    # Construct the new block
    new_block = []
    
    if block_start < start_idx:
        new_block.extend(lines[block_start:start_idx])
    
    for l in new_license_lines:
        new_block.append(prefix + l + "\n")
        
    if block_end > end_idx:
        new_block.extend(lines[end_idx+1:block_end+1])

    new_lines = lines[:block_start] + new_block + lines[block_end+1:]

    try:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.writelines(new_lines)
        return True
    except Exception as e:
        print(f"Failed to write {filepath}: {e}")
        return False

def main():
    root_dir = sys.argv[1]
    extensions = {'.c', '.cpp', '.cxx', '.h', '.hxx', '.hpp', '.java', '.py', '.js', '.css', '.html', '.xml', '.mk', '.sh', '.bat', '.cmd', '.pl', '.pm'}
    count = 0
    for dirpath, dirnames, filenames in os.walk(root_dir):
        # Skip git and other hidden dirs
        dirnames[:] = [d for d in dirnames if not d.startswith('.')]
        for filename in filenames:
            ext = os.path.splitext(filename)[1].lower()
            if ext in extensions or filename in ['Makefile', 'README', 'NOTICE', 'LICENSE']:
                filepath = os.path.join(dirpath, filename)
                if process_file(filepath):
                    count += 1
                    if count % 1000 == 0:
                        print(f"Processed {count} files...")
    
    print(f"Total files updated: {count}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python replace_agpl.py <dir>")
        sys.exit(1)
    main()
