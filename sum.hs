import System.IO.Error
import Data.Maybe

main :: IO ()
main = print =<< sum <$> untilNothing safeReadLn

safeReadLn :: Read a => IO (Maybe a)
safeReadLn = catchIOError (Just <$> readLn) (const $ pure Nothing)

untilNothing :: IO (Maybe b) -> IO [b]
untilNothing action = do
  mayX <- action
  case mayX of
    Nothing -> pure []
    Just x -> (x:) <$> untilNothing action
