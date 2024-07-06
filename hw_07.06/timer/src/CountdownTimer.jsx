import React, { useState, useEffect } from 'react';

const CountdownTimer = () => {
    const [time, setTime] = useState(0);
    const [inputTime, setInputTime] = useState('');
    const [isRunning, setIsRunning] = useState(false);
    const [intervalId, setIntervalId] = useState(null);

    useEffect(() => {
        if (isRunning && time > 0) {
            const id = setInterval(() => {
                setTime(prevTime => prevTime - 1);
            }, 1000);
            setIntervalId(id);
            return () => clearInterval(id);
        } else if (time === 0 && isRunning) {
            setIsRunning(false);
            clearInterval(intervalId);
        }
    }, [isRunning, time]);

    const startTimer = () => {
        if (!isRunning && time > 0) {
            setIsRunning(true);
        }
    };

    const stopTimer = () => {
        setIsRunning(false);
        clearInterval(intervalId);
    };

    const resetTimer = () => {
        setIsRunning(false);
        clearInterval(intervalId);
        setTime(0);
        setInputTime('');
    };

    const handleInputChange = (event) => {
        setInputTime(event.target.value);
    };

    const setTimer = () => {
        const seconds = parseInt(inputTime, 10);
        if (!isNaN(seconds)) {
            setTime(seconds);
        }
    };

    return (
        <div>
            <h1>Таймер обратного отсчета</h1>
            <div>
                <input
                    type="number"
                    value={inputTime}
                    onChange={handleInputChange}
                    placeholder="Введите время в секундах"
                />
                <button onClick={setTimer}>Установить время</button>
            </div>
            <div>
                <h2>{time} секунд</h2>
            </div>
            <div>
                <button onClick={startTimer} disabled={isRunning || time === 0}>Запустить</button>
                <button onClick={stopTimer} disabled={!isRunning}>Остановить</button>
                <button onClick={resetTimer}>Сбросить</button>
            </div>
        </div>
    );
};

export default CountdownTimer;
