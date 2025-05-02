SELECT
    c.CAR_ID,
    c.CAR_TYPE,
    -- 30일간 대여 시 할인 적용 후 금액을 소수점 없이 반올림
    ROUND(c.DAILY_FEE * 30 * (100 - p.DISCOUNT_RATE) / 100, 0) AS FEE
FROM
    CAR_RENTAL_COMPANY_CAR AS c
-- 할인율 정보 조인
INNER JOIN
    CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS p
  ON c.CAR_TYPE = p.CAR_TYPE
WHERE
    -- 조회 기간(11월) 동안 단 한 번도 렌탈 이력이 없어야 함
    c.CAR_ID NOT IN (
        SELECT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE
            END_DATE   >= '2022-11-01'
            AND START_DATE <  '2022-12-01'
    )
    -- 차종 필터
    AND (c.CAR_TYPE = '세단' OR c.CAR_TYPE = 'SUV')
    -- 30일 이상 대여 시 적용되는 할인율만 사용
    AND p.DURATION_TYPE = '30일 이상'
GROUP BY
    c.CAR_ID
HAVING
    -- 총 대여비용 범위 필터 (500,000원 이상, 2,000,000원 미만)
    FEE BETWEEN 500000 AND 1999999
ORDER BY
    FEE      DESC,
    CAR_TYPE ASC,
    CAR_ID   DESC;
