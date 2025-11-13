pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Configure CMake') {
            steps {
                dir('Lab4') {
                    bat '''
                    cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug
                    '''
                }
            }
        }

        stage('Build') {
            steps {
                dir('Lab4') {
                    bat '''
                    cmake --build build -j
                    '''
                }
            }
        }

        stage('Run Tests') {
            steps {
                dir('Lab4') {
                    bat '''
                    build\\runTests.exe --gtest_output=xml:build/test_reports/test_report.xml
                    '''
                }
            }
        }
    }

    post {
        always {
            junit 'Lab4/build/test_reports/*.xml'
        }
    }
}
