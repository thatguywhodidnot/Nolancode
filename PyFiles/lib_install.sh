#!/bin/bash

# Bash script to install the most useful Python libraries

echo "Updating pip..."
python3 -m pip3 install --upgrade pip3

# Define a list of libraries to install
libraries=(
    numpy              # Numerical computing
    pandas             # Data manipulation
    matplotlib         # Plotting
    seaborn            # Statistical data visualization
    scikit-learn       # Machine learning
    scipy              # Scientific computing
    jupyter            # Jupyter notebooks
    ipython            # Enhanced Python REPL
    requests           # HTTP requests
    beautifulsoup4     # HTML/XML parsing
    lxml               # XML processing
    flask              # Lightweight web framework
    fastapi            # Fast web APIs
    uvicorn            # ASGI server for FastAPI
    sqlalchemy         # SQL toolkit and ORM
    psycopg2-binary    # PostgreSQL database adapter
    openpyxl           # Excel file handling
    tqdm               # Progress bars
    pillow             # Image processing
    python-dotenv      # Environment variable management
    pyautogui          # GUI automation
    pytest             # Testing framework
    black              # Code formatter
    mypy               # Static type checker
    virtualenv         # Virtual environments
)

echo "Installing Python libraries..."
for lib in "${libraries[@]}"
do
    echo "Installing $lib..."
    pip3 install "$lib"
done

/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install ffmpeg

echo "All libraries installed successfully."
